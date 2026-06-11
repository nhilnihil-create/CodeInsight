#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

long long MOD = 1000000007;

int main(){
    int N;
    cin >> N;
    vector<int> cnt(N,0);
    for(int i=0; i<N; i++){
        int p;
        cin >> p;
        p--;
        if(i==0){
            cnt[p]=1;
        }else{
            cnt[p]=cnt[p-1]+1;
        }
    }

    int ans=N;
    for(int i=0; i<N; i++){
        ans=min(ans,N-cnt[i]);
    }
    cout << ans << endl;
}