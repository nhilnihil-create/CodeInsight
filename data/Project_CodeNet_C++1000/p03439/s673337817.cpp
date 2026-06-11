#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(v) v.begin(),v.end()
#define mem(arr) memset(arr, 0, sizeof(arr))
#define ff first
#define ss second
#define int long long int
const int MOD = 1e9 + 7;
const int INF = 1e18;
const int N = 1e6 + 20;
vector<int> g[N];
vector<int> vis(N);
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc = 1;
    while(tc--){
        int n;
        cin >> n;
        string s;
        cout << "0\n";
        cout << flush;
        cin >> s;
        if(s == "Male"){
            int l = 0, r = n - 1;
            while(l <= r){
                int mid = (l + r) / 2;
                cout << mid << '\n';
                cout << flush;
                string str;
                cin >> str;
                if(str == "Vacant"){
                    return 0;
                }
                if(mid % 2){
                    if(str == "Female"){
                        l = mid + 1;
                    }else{
                        r = mid - 1;
                    }
                }else{
                    if(str == "Male"){
                        l = mid + 1;
                    }else{
                        r = mid - 1;
                    }
                }
            }
        }else{
           int l = 0, r = n - 1;
            while(l <= r){
                int mid = (l + r) / 2;
                cout << mid << '\n';
                cout << flush;
                string str;
                cin >> str;
                if(str == "Vacant"){
                    return 0;
                }
                if(mid % 2){
                    if(str == "Male"){
                        l = mid + 1;
                    }else{
                        r = mid - 1;
                    }
                }else{
                    if(str == "Female"){
                        l = mid + 1;
                    }else{
                        r = mid - 1;
                    }
                }
            } 
        }
    }
}