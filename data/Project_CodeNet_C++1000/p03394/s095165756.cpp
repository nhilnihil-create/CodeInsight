#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
#include <bitset>
#include <cmath>
#include <limits>
#include <iostream>
#include<set>
#include<tuple>
using namespace std;
#define INF 11000000000
#define MAX 5100
#define MOD 1000000007
typedef long long ll;
typedef pair<int,int> P;
typedef pair<pair<int,int>,int> p;
typedef pair< pair<int,int>, int> p; 
#define bit(n,k) ((n>>k)&1) /*nのk bit目*/
#define rad_to_deg(rad) (((rad)/2/M_PI)*360)
const double PI = acos(-1);

int main(){
    int N;
    cin>>N;
    string ans;
    vector<int> A;
    if(N==3) ans="2 5 63";
    else if(N==4) ans="2 5 20 63";
    else if(N==5) ans="2 5 20 30 63";
    if(N<=5){
        cout<<ans<<endl;
        return 0;
    }
    ll sum=0;
    for(int i=0;i<N;i++){
        int x;
        if(i%4==0) x=i/4*6+2;
        else if(i%4==1) x=i/4*6+3;
        else if(i%4==2) x=i/4*6+4;
        else if(i%4==3) x=i/4*6+6;
        A.push_back(x);
        sum+=x;
    }
    int x;
    if(sum%6==2){
        x=8; A.push_back(30000);
    }else if(sum%6==3){
        x=9; A.push_back(30000);
    }else if(sum%6==5){
        x=9; A.push_back(29998);
    }else{
        x=-1;
    }
    for(int i=0;i<(int)A.size();i++){
        int temp=A[i];
        if(temp==x) continue;

        cout<<temp<<endl;;
    }

}

