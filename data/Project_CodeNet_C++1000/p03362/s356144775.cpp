#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);



    bool is_prime[55556];
    is_prime[0] = is_prime[1] = false;

    for (int a=2; a<55556; a++) {
        is_prime[a]=true;
    }

    for (int a=2; a<55556; a++) {
        if(is_prime[a]) {
            for(int b=2; b*a<55556; b++) {
                is_prime[b*a] = false;
            }
        }
    }

    vector<int> five;
    for (int a=2; a<55556; a++) {
        if(is_prime[a] && a%10 == 3) {
            five.push_back(a);
        }
    }

    int n;
    cin >> n;

    for (int i=0; i<n; i++) {
        cout << five[i] << " ";
    }

}
