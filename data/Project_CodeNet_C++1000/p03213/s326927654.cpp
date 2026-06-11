#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    vector<int> prime(0);
    prime.push_back(2);
    prime.push_back(3);
    prime.push_back(5);
    prime.push_back(7);
    prime.push_back(11);
    prime.push_back(13);
    prime.push_back(17);
    prime.push_back(19);
    prime.push_back(23);
    prime.push_back(29);
    prime.push_back(31);
    prime.push_back(37);
    prime.push_back(41);
    prime.push_back(43);
    prime.push_back(47);
    prime.push_back(53);
    prime.push_back(59);
    prime.push_back(61);
    prime.push_back(67);
    prime.push_back(71);
    prime.push_back(73);
    prime.push_back(79);
    prime.push_back(83);
    prime.push_back(89);
    prime.push_back(97);
    
    int N;
    cin >> N;
    vector<int> prime_count(25,0);
    for (int i = 2; i <= N; i++){
        int i_copy = i;
        int j = 0;
        while(true){
            if (i_copy == 1){
                break;
            }
            else if (i_copy % prime[j] == 0){
                i_copy /= prime[j];
                prime_count[j]++;
            }
            else{
                j++;
            }
        }
    }
    int over_2 = 0;
    int over_4 = 0;
    int over_14 = 0;
    int over_24 = 0;
    int over_74 = 0;
    for (int i = 0; i < 25; i++){
        if (prime_count[i] >= 74) over_74++;
        else if (prime_count[i] >= 24) over_24++;
        else if (prime_count[i] >= 14) over_14++;
        else if (prime_count[i] >= 4) over_4++;
        else if (prime_count[i] >= 2) over_2++;
    }
    int ans = 0;
    ans += over_2 * (over_4 + over_14 + over_24 + over_74) * (over_4 + over_14 + over_24 + over_74 - 1) / 2;
    ans += (over_4 + over_14 + over_24 + over_74) * (over_4 + over_14 + over_24 + over_74 - 1) * (over_4 + over_14 + over_24 + over_74 - 2) / 2;
    ans += (over_2 + over_4 + over_14) * (over_24 + over_74);
    ans += (over_24 + over_74) * (over_24 + over_74 - 1);
    ans += over_4 * (over_14 + over_24 + over_74);
    ans += (over_14 + over_24 + over_74) * (over_14 + over_24 + over_74 - 1);
    ans += over_74;
    cout << ans << endl;
}