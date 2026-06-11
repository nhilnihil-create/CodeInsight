#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> x(n);
    for(int i = 0; i < n; i++) cin >> x[i];
    vector<int> memo(n);
    for(int i = 0; i < n; i++) memo[i] = x[i];
    sort(memo.begin(), memo.end());

    for(int i = 0; i < n; i++){
        int left = -1;
        int right = n;
        int mid;
        do{
            mid = (left + right)/2;
            if(memo[mid] == x[i]) break;
            else if(memo[mid] < x[i]) left = mid+1;
            else right = mid-1;
        }while(right > left);

        if(mid >= n/2) cout << memo[n/2-1] << endl;
        else cout << memo[n/2] << endl;
    }
    return 0;
}