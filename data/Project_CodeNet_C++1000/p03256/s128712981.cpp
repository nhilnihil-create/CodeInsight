#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#include <climits>
#include <string>
#include <map>
#include <set>
#include <list>

#define ll long long
#define fornum(A,B,C) for(A=B;A<C;A++)

using namespace std;

int i,j,k,l,m,n;
/////////////////////////////////////////////////////
#define mp make_pair

int N,M;
char s[202020];
int a[202020],b[202020];
vector<int> ab[202020];
int cont[202020][2];
vector<int> nonodes;

int main(){
    scanf("%d%d",&N,&M);
    scanf("%s",s);
    for(i=1;i<=M;i++){
        scanf("%d%d",&a[i],&b[i]);
        ab[a[i]].push_back(b[i]);
        ab[b[i]].push_back(a[i]);
        cont[a[i]][s[b[i]-1]-'A']++;
        cont[b[i]][s[a[i]-1]-'A']++;
    }
    for(i=1;i<=N;i++){
        if(cont[i][0]*cont[i][1])
            continue;
        //printf("%d ",i);
        nonodes.push_back(i);
    }

    for(j=0;j<nonodes.size();j++){
        int AB=s[nonodes[j]-1]-'A';
        for(i=0;i<ab[nonodes[j]].size();i++){
            if(--cont[ab[nonodes[j]][i]][AB]==0
            &&cont[ab[nonodes[j]][i]][!AB]!=0){
                //printf("%d ",ab[nonodes[j]][i]);
                nonodes.push_back(ab[nonodes[j]][i]);
            }
            //printf("%d:%d ",ab[nonodes[j]][i],cont[ab[nonodes[j]][i]][AB]);
        }    
    }
    if(nonodes.size()==N){
        printf("No\n");
    }else{
        printf("Yes\n");
    }
    return 0;
}