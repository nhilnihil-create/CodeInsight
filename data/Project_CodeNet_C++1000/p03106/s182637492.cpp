#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
using namespace std;
int main(void){
    int A,B,K;
    cin>>A>>B>>K;
    vector<int> ans;
    for(int i=1;i <= min(A,B);i++){
        if(A % i == 0 && B % i == 0){
            ans.push_back(i);
        }
    }
    sort(ans.begin(),ans.end(),greater<>());
    cout << ans[K-1] << endl;
    
}
