#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
#include <bitset>
#include<math.h>
using namespace std;
#define INF 11000000000000
#define MOD 1000000007
typedef long long ll;
typedef pair<string,string> P;


int main(){
    int N;
    string s,t;
    P ans[500000];
    ll a;
    cin>>N>>s;
    for(int i=2*N-1;i>=N;i--) t.push_back(s[i]);
    //cout<<t<<endl;

    for(int bit=0;bit<(1<<N); bit++){
        string temp,temp2;
        for(int i=0;i<N;i++){
            if(bit>>i & 1){
                temp.push_back(s[i]);
            }else temp2.push_back(s[i]);
        }

        ans[bit].first=temp; ans[bit].second=temp2;
    }
    sort(ans,ans+(1<<N));

    for(int bit=0;bit<(1<<N); bit++){
        string temp,temp2;
        for(int i=0;i<N;i++){
            if(bit>>i & 1){
                temp.push_back(t[i]);
            }else temp2.push_back(t[i]);
        }
        a+=(int)(upper_bound(ans,ans+(1<<N),P(temp,temp2))-lower_bound(ans,ans+(1<<N),P(temp,temp2)));
        //cout<<a<<endl;
        //cout<<temp<<endl;
    }

    cout<<a<<endl;
}

