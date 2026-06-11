#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    vector<int> vec(3);
    for (int i=0; i<3; i++){
        cin >> vec[i];
    }
    sort(begin(vec), end(vec));
    int ans=0;
    ans += (vec[1] - vec[0]) / 2;
    vec[0] += ans * 2;
    if (vec[0] != vec[1]){
        vec[2] += 1;
        ans += 1;
    } 
    ans += vec[2] - vec[1];
    cout << ans << endl;
    return 0;
}