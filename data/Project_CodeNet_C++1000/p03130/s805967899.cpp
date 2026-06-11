#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    vector<int>sr(4,0);
    int a;
    for(int i=0; i<6; i++){
        cin >> a;
        a--;
        sr[a]++;
    }
    sort(sr.begin(),sr.end());
    if(sr[0]==1 && sr[1]==1 && sr[2]==2 && sr[3]==2){
        puts("YES");
    }else{
        puts("NO");
    }
    return 0;
}