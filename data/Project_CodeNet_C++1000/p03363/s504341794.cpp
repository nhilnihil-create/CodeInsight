#include <iostream>
#include <map>
#define ll long long
using namespace std;

map <ll, int> freq;
ll arr[200005];
ll prefsum[200005];
int main()
{
    int n;
    cin >> n;
    
    prefsum[0] = 0;
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
        prefsum[i] = prefsum[i-1] + arr[i];
    }
    
    freq[0] = 1;
    ll ans = 0;
    for (int i = 1; i <= n; i++){
        ll g = prefsum[i];
        ll f = freq[g];
        if (f > 0){
            ans = ans + f;
        }
        freq[g]++;
    }
    
    
    cout << ans << endl;
    return 0;
}
