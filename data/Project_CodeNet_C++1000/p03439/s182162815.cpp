#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    long long n;
    cin >> n;
    vector<bool> seats(20);
    string first, last;
    long long l = 0, r = n-1;
    cout << 0 << endl;
    cin >> first;
    if(first == "Vacant") return 0;
    cout << n-1 << endl;
    cin >> last;
    if(last == "Vacant") return 0;
    long long rem = 18;
    while(rem > 0){
        long long pos = (l+r)/2;
        string tmp;
        cout << pos << endl;
        cin >> tmp;
        if(tmp == "Vacant") return 0;
        if((tmp == last) ^ ((r-pos)%2 == 0)){
            l = pos;
            first = tmp;
        }
        else{
            r = pos;
            last = tmp;
        }
        rem--;
    }
    return 0;
}