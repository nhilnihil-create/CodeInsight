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
typedef pair<pair<int,int>,int> p;
typedef pair< pair<int,int>, int> p; 
#define bit(n,k) ((n>>k)&1) /*nのk bit目*/
#define rad_to_deg(rad) (((rad)/2/M_PI)*360)

int C[3];

int main(){
    int N,A,B,Q;
    cin>>N>>A>>B;
    for(int i=0;i<N;i++){
        cin>>Q;
        if(Q<=A) C[0]++;
        else if(Q<=B) C[1]++;
        else C[2]++;
    }
    cout<<min(  C[0], min(C[1],C[2])    )<<endl;
}

