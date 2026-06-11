#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#define ll long long
using namespace std;
int main(){
    int n;
    string s;
    cin>>n>>s;
    vector<int> esum(n+1,0);
    vector<int> wsum(n+1,0);
    for(int i=0;i<n;i++){
        if('E'==s[i]){
            esum[i+1]=esum[i]+1;
            wsum[i+1]=wsum[i];
        }else{
            esum[i+1]=esum[i];
            wsum[i+1]=wsum[i]+1;
        }
    }
    int min=1000000;
    for(int i=0;i<n;i++){
        int sum=wsum[i]+(esum.back()-esum[i+1]);
        if(min>sum){
            min=sum;
        }
    }
    cout<<min<<endl;
    return 0;
}