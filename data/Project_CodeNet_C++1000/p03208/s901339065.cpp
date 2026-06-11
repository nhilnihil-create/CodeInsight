#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<map>

using namespace std;

int main(void){

    int n, k, ans = 1000000007;
    cin >> n >> k;

    vector<int> h(n);

    for(int i = 0;i < n;i++){
        cin >> h[i];
    }

    sort(h.begin(), h.end());

    int tmp;
    for(int i = 0;i < n - k + 1;i++){
        tmp = h[i+k-1] - h[i];
        if(ans > tmp){
            ans = tmp;
        }
    }

    cout << ans << endl;

    return 0;
}
