#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define FOR(i,n,j) for(int i=(j);i<(n);++i)
using namespace std;
using ll=long long;
using ld=long double;
#define ssort(n) sort((n).begin(),(n).end())
typedef pair<int,int> P;

int main()
{
    int N;
    cin >> N;
    vector<int> h(N);
    rep(i,N)cin >> h[i];

    int count=0;
    int max=0;
    rep(i,N){
        if(max<h[i]){
            max=h[i];
        }
    }
    bool flag=false;
    rep(i,max){
        rep(j,N){
            if(h[j]>0&&!flag){
                flag=true;
                h[j]--;
            }else if(h[j]>0&&flag){
                h[j]--;
            }else if(h[j]==0&&flag){
                count++;
                flag=false;
            }if(j==N-1&&flag){
                count++;
                flag=false;
            }
        }
    }
    cout << count << endl;
}