#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<cstdio>
#include<queue>
#include<deque>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
typedef pair<ll,ll> pll;
const int INF=1e9;
const ll MOD=1e9+7;

ll gcd(ll x,ll y){
    if(y==0) return 0;
    return gcd(y,x%y);
}

int dis2(int x1,int y1,int x2,int y2){
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

int main(){
    string s;cin>>s;
    if(s=="KIHBR"||s=="AKIHBR"||s=="KIHABR"||s=="KIHBAR"||s=="KIHBRA"
    ||s=="AKIHABR"||s=="AKIHBAR"||s=="AKIHBRA"||s=="KIHABAR"||s=="KIHABRA"
    ||s=="KIHBARA"||s=="AKIHABAR"||s=="AKIHABRA"||s=="AKIHBARA"
    ||s=="KIHABARA"||s=="AKIHABARA"){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    return 0;
}