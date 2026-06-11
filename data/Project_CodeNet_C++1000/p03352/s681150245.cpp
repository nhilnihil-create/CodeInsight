#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N = 0;
    cin >> N;
    int temp;
    int ans = 0;
    for (size_t i = 2; i < 32; i++)
    {
        temp = log(N)/log(i);
        //cout << "(" << temp << "," << i << ")" << endl;
        if (temp == 1)
        {
            continue;
        }
       
        if(ans < pow(i,temp)){
                ans = pow(i,temp);
                //cout << temp << endl;
            //    cout << ans << endl;
        }
        temp++;
        if (N<pow(i,temp))
        {
            continue;
        }
        
        if(ans < pow(i,temp)){
                ans = pow(i,temp);
                //cout << temp << endl;
        //        cout << ans << endl;
        }
    }
    
    cout << ans << endl;
    

    return 0;
}