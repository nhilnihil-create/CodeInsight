#include <bits/stdc++.h>
 
#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define endl "\n"
#define ii pair<int,int>
#define qu queue <int>
#define qmax priority_queue <int>
#define qmin priority_queue <int, vector<int>,greater<int>>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,T,costMin=100000;

    cin>>n>>T;

    int c,t;

    for(int i=0; i<n; i++){
        cin>>c>>t;

        if(c <= costMin && t<= T){
            costMin = c;
            
        }
    }

    if(costMin!=100000)
        cout<<costMin<<endl;
    else
        cout<<"TLE"<<endl;
    return 0;
}