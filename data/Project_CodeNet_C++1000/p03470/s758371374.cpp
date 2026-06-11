#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N,tmp=0,cnt=0;
    scanf("%d",&N);
    vector<int>d(N);
    for(int i=0; i<N; i++) scanf("%d",&d[i]);
    sort(d.begin(),d.end());
    for(int i=0; i<N; i++){
        if(tmp==d[i]){
        }else{
            cnt++;
            tmp=d[i];
        }
    }
    printf("%d\n",cnt);
    return 0;
}