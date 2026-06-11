#include <bits/stdc++.h>
using namespace std;
int getCost(int *arr, int index, vector<int>& mem){
    if(mem[index] != -1) return mem[index];

    int cost = INT_MAX;
    if(index+1 < mem.size())
        cost = min(cost, abs(arr[index] - arr[index+1])+ getCost(arr, index+1, mem));
    if(index+2 < mem.size())
        cost = min(cost, abs(arr[index] - arr[index+2])+getCost(arr, index+2, mem));
    
    if(cost == INT_MAX)
        cost = 0;
    mem[index] = cost;
    return cost;

}
int main(){
    int N;
    cin >> N;

    int *arr = new int[N];

    for(int i = 0; i < N; i++)
        cin >> arr[i];

    vector<int> mem(N, -1);

    int ans = getCost(arr, 0, mem);
    cout << ans << endl;
}