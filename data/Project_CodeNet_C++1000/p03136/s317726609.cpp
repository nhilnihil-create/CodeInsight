#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int sum = 0, longest = 0;
    for (int i=0; i<n; i++) {
        int l;
        cin >> l;
        sum += l;
        longest = max(longest, l);
    }
    cout << ((sum > longest*2) ? "Yes" : "No") << endl;
}