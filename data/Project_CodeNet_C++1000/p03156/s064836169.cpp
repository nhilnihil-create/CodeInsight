#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, a, b;
    cin >> n >> a >> b;

    vector<int> problem(3);
    for(int i=0; i<n; i++){
        int p;
        cin >> p;
        if(p <= a) problem[0] += 1;
        if(a+1 <= p && p <= b) problem[1] += 1;
        if(b+1 <= p) problem[2] += 1;
    }
    sort(problem.begin(),problem.end());
    cout << problem[0] << endl;
    return 0;
}