#include <bits/stdc++.h>
using namespace std;
int getCount(vector<int> &arr, int index, int K, vector<int>& mem){
    if(mem[index] != -1) return mem[index];

    int ans = INT_MAX;

    for(int i = 1; i <= K && index+i < arr.size(); i++){
        ans = min(ans, abs(arr[index] - arr[index+i])+getCount(arr, index+i, K, mem));
    }

    if(ans == INT_MAX)
        ans = 0;
    
    mem[index] = ans;
    return ans;
}
int main(){
    int N, K;
    cin >> N >> K;

    vector<int> arr(N);

    for(int i = 0; i < N; i++)
        cin >> arr[i];

    vector<int> mem(N, -1);

    cout << getCount(arr, 0, K, mem) << endl;

}