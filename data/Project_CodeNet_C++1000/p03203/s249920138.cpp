#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define rer(i, a, b) for(int i = int(a) - 1; i >= int(b); i--)

using namespace std;
typedef long long int ll;
typedef pair <int, int> P;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int H,W,N;
    cin>> H>>W>>N;
    if(N>=1){
        int X[N], Y[N], Z[N];
        rep(i,0,N) {
            cin>>X[i]>>Y[i];
            Z[i]=X[i]-Y[i];
        }
        P p[N];
        rep(i,0,N) p[i]=make_pair(X[i], Z[i]);
        sort(p,p+N);
        int temp1=0, temp2=0;
        if(p[temp1].second>=1) {
            cout<<p[temp1].first-1<<"\n";
            return 0;
        }
        else{
            rep(i,1,N){
                if(p[temp2].first<p[i].first&&p[temp2].second<p[i].second){
                    if(p[i].second>max(p[temp2].second+1,0)){
                        if(temp1==0){
                            if(!(p[temp1].first+1==p[i].first&&p[temp1].second+1==p[i].second)){
                                cout<<p[i].first-1<<"\n";
                                return 0;
                            }
                        }
                        else{
                            if(!(p[temp1].first+1==p[i].first&&p[temp1].second+1==p[i].second)&&!(p[temp1-1].first+1==p[i].first&&p[temp1-1].second+1==p[i].second)){
                                cout<<p[i].first-1<<"\n";
                                return 0;
                            }
                        }
                    }
                    temp1=temp2;
                    temp2=i;
                }
                else{
                    if(p[temp2].first==p[i].first){
                        if(p[i].second>max(p[temp1].second+1,0)){
                            if(temp1==0){
                                if(!(p[temp1].first+1==p[i].first&&p[temp1].second+1==p[i].second)){
                                    cout<<p[i].first-1<<"\n";
                                    return 0;
                                }
                            }
                            else{
                                if(!(p[temp1].first+1==p[i].first&&p[temp1].second+1==p[i].second)&&!(p[temp1-1].first+1==p[i].first&&p[temp1-1].second+1==p[i].second)){
                                    cout<<p[i].first-1<<"\n";
                                    return 0;
                                }
                            }
                        }
                        temp2++;
                    }
                }
            }
        }
        cout<<H<<"\n";
    }
    else cout<<H<<"\n";
}
