#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

int main(void) {
    int N, A, B;
    cin >> N >> A >> B;
    
    int ans = 0;
    string i_str;
    for (int i = 1; i <= N; i++) {
        int j = 0;
        int tmp = 0;
        i_str = to_string(i);
        while(i_str[j]){
            tmp += i_str[j] - '0';
            j++;
        }
        if (A <= tmp && tmp <= B)
            ans += i;
    }

    cout << ans << endl;
    
    return 0;
}