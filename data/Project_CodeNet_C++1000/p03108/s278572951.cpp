#include<bits/stdc++.h>
#define rp(i,n) for(int i=0; i<n; i++)
using namespace std;
using ll=long long;
using P=pair<int,int>;
class UnionFind {
    public:
        //親の番号を格納する。親だった場合は-(その集合のサイズ)
         vector<int> Parent;

        //作るときはParentの値を全て−1にする
        //こうすると全てバラバラになる
        UnionFind(int N){
            Parent = vector<int>(N+1, -1);
        }

        //Aがどのグループに属しているか調べる
        int root(int A) {
            if(Parent[A] < 0) return A;
            return Parent[A] = root(Parent[A]);
        }

        //自分のいるグループの頂点数を調べる
        int size(int A){
            return -Parent[root(A)];//親をとってきたい
        }

        //AとBをくっつける
        bool connect(int A, int B){
            //AとBを直接つなぐのではなく、root(A)にroot(B)をくっつける
            A=root(A);
            B=root(B);
            if(A==B){
                return false;
            }

            if(size(A) < size(B)) swap(A,B);

            Parent[A] += Parent[B];
            Parent[B]=A;
            return true;
        }
};
int main(){
    int n,m;
    cin >> n >> m;
    vector<int> a(m),b(m);
    rp(i,m){
        cin >> a.at(i) >> b.at(i);
        //a.at(i)--;
        //b.at(i)--;
    }
    UnionFind uni(n);
    vector<ll> ans(m,0ll); 
    ans.at(m-1)=(ll) n*(n-1)/2;
    for(int i=m-1; i>=1; i--){
        ans[i-1]=ans[i];
        int as=uni.size(a[i]),bs=uni.size(b[i]);
        if(uni.connect(a[i],b[i])){
            //cout << "here" << endl;
            ans[i-1] -= (ll)as*bs;
        }
    }
    rp(i,m) cout << ans[i] << endl;
    return 0;
}