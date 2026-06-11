#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
#include <bitset>
#include<math.h>
#include<map>
#include<set>
#include <climits>
using namespace std;
#define INF 11000000000
#define MOD 1000000007
typedef long long ll;
typedef pair<int,int> P;

int C[10];

int main(){
    int n;
    for(int i=0;i<4;i++){
        cin>>n;
        C[n]++;
    }
    if(C[1] && C[9] && C[7] && C[4]){
        cout<<"YES"<<endl;
    }else cout<<"NO"<<endl;
}
