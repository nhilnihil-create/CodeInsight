#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
typedef long long ll;
const int INF = 1e+9+7;

int main(){
    int N,A,B,C;
    cin >> N >> A >> B >> C;
    vector<int> l(N);
    rep(i,N) cin >> l[i];
    int d_l=INF;
    int l_a=0;
    int l_b=0;
    int l_c=0;

    sort(l.begin(),l.end());

    do{
        rep2(num,3,N+1){
            rep2(i,1,num-1){
                rep2(j,i+1,num){
                    l_a=0;
                    l_b=0;
                    l_c=0;
                    rep(k,i){
                        l_a+=l[k];
                    }

                    rep2(k,i,j){
                        l_b+=l[k];
                    }

                    rep2(k,j,num){
                        l_c+=l[k];
                    }
                    d_l=min(d_l,10*(num-3)+abs(l_a-A)+abs(l_b-B)+abs(l_c-C));
                    d_l=min(d_l,10*(num-3)+abs(l_a-B)+abs(l_b-C)+abs(l_c-A));
                    d_l=min(d_l,10*(num-3)+abs(l_a-C)+abs(l_b-A)+abs(l_c-B));
                    d_l=min(d_l,10*(num-3)+abs(l_a-A)+abs(l_b-C)+abs(l_c-B));
                    d_l=min(d_l,10*(num-3)+abs(l_a-B)+abs(l_b-A)+abs(l_c-C));
                    d_l=min(d_l,10*(num-3)+abs(l_a-C)+abs(l_b-B)+abs(l_c-A));

                }
            }
        }
        
    }while(next_permutation(l.begin(),l.end()));

    
    cout << d_l << endl;
}