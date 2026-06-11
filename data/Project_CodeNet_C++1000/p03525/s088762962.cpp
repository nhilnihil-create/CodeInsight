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

int C[30];

int main(){
    int N;
    cin>>N;
    C[0]++;
    for(int i=0;i<N;i++){
        int d;
        cin>>d;
        C[d]++;
    }
    for(int i=0;i<23;i++){
        if(C[i]<=1) continue;
        if(C[i]>=3){
            cout<<0<<endl;
            return 0;
        }
        if(i==0 || i>=12){
            cout<<0<<endl;
            return 0;
        }
        C[24-i]++;
    }
    vector<int> V,T;
    for(int i=0;i<=12;i++){
        if(i==0 || i==12){
            if(C[i]) V.push_back(i);
            continue;
        }
        if(C[i] && C[24-i]){
            V.push_back(i);
            V.push_back(24-i);
        }else if(C[i] || C[24-i]){
            T.push_back(i);
        }
    }
    int nV=(int)V.size(),nT=(int)T.size();
    int ans=0;
    for(int S=0;S<(1<<nT);S++){
        vector<int> D;
        for(int i=0;i<nV;i++){
            D.push_back(V[i]);
        }

        for(int i=0;i<nT;i++){
            if(bit(S,i)) D.push_back(24-T[i]);
            else D.push_back(T[i]);
        }
        D.push_back(24);
        int temp=24;
        for(int i=0;i<(int)D.size();i++){
            for(int j=i+1;j<(int)D.size();j++){
                temp=min(temp,   abs(D[i]-D[j])   );
            }
        }

        ans=max(ans,temp);
    }
    cout<<ans<<endl;
}

