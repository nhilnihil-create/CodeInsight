#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    // inch-worm
    long long int count = 0;
    int right = 0;
    int sum = 0;
    for(int left=0; left<n; left++){
        while(right < n && (sum ^ a[right]) == (sum + a[right])){
            sum += a[right];
            right += 1;
        }
        count += right - left;

        if(left == right) right += 1;
        if(left <  right) sum -= a[left];
    }
    cout << count << endl;
    return 0;
}