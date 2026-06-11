#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define SIZE 200005
#define INF 1000000005LL
#define MOD 1000000007
using namespace std;
typedef long long int ll;
typedef pair <int,int> P;
int main(){
    int n,m;
    cin >> n >> m;
    
    vector<int> data(m);
    rep(i,0,m){
        cin >> data[i];
    }
    if(m==1){
        cout<<0<<endl;
        return 0;
    }
    if(n>=m){
        cout<<0<<endl;
        return 0;
    }
    sort(data.begin(),data.end());
    vector<int> distance(m-1);
    rep(i,0,m-1){
        distance[i]=data[i+1]-data[i];
    }
    sort(distance.begin(),distance.end());
    reverse(distance.begin(),distance.end());
    int total = data[m-1]-data[0];
    rep(i,0,n-1){
        total -= distance[i];
    }
    cout<<total<<endl;
    


    return 0;
}