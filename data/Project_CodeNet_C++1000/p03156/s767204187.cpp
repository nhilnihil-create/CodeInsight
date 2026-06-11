#include<bits/stdc++.h>
using namespace std;

int main(){
        int n;
        int a,b;
        cin >> n >> a >> b;
        int p;
        int q1 = 0;
        int q2 = 0;
        int q3 = 0;

        for (int i=0; i<n; i++){
                cin >> p;
                if (p <= a) q1++;
                else if (a < p && p <= b) q2++;
                else q3++;
        }

        cout << min(min(q1,q2),q3) << endl;

        return 0;
}