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
#define MAX 100000
#define MOD 1000000007
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,pair<int,int> >  p; 
#define bit(n,k) ((n>>k)&1) /*nのk bit目*/
#define rad_to_deg(rad) (((rad)/2/M_PI)*360)
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};


int main(){
    string s;
    cin>>s;
    int count=0;
    for(int i=0;i<(int)s.size();i++){
        if(s[i]=='o') count++;
    }
    int n=(int)s.size();
    n=15-n;
    if(count+n>=8) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

