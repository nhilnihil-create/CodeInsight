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
#include<map>
#include<tuple>
using namespace std;
#define INF 11000000000
#define MAX 110000
#define MOD 1000000007
typedef long long ll;
typedef pair<int,int> P;
typedef pair<pair<int,int>,int> p;
typedef pair< pair<int,int>, int> p; 
#define bit(n,k) ((n>>k)&1) /*nのk bit目*/
#define rad_to_deg(rad) (((rad)/2/M_PI)*360)


int main(){
    int N;
    cin>>N;
    int count=0;
    string a,b,c;
    cin>>a>>b>>c;
    for(int i=0;i<N;i++){
        if(a[i]==b[i] && b[i]==c[i]) continue;
        if(a[i]!=b[i] && b[i]!=c[i] && c[i]!=a[i]) count+=2;
        else count++;
    }
    cout<<count<<endl;
}

