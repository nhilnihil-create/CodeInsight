#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF=1LL<<60;
const int inf=1<<30;
const int mod=1e9+7;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    vector<bool> p(55556,true);
    p[0]=false;
    p[1]=false;
    for(int i=2;i*i<=55555;i++){
        if(p[i]){
            for(int j=2;j*i<=55555;j++){
                p[i*j]=false;
            }
        }
    }
    int n;cin >> n;
    vector<int> a;
    for(int i=0;i<=55555;i++){
        if(p[i]){
            if(i%5==1){
                a.push_back(i);
            }
        }
    }
    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }
    cout << endl;
}