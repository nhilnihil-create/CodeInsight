#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long int ll;
typedef pair<int, int> P;

int n;

int main()
{
    cin >> n;
    int lb = 0;
    cout << lb << "\n";
    string ls;
    cin >> ls;
    int ub = n;
    string s;
    int cnt = 0;
    while(ls != "Vacant" && cnt <= 100000)
    {
        int mid = (ub + lb) / 2;
        cout << mid << "\n";
        cin >> s;
        if((mid - lb) % 2 == 0)
        {
            if(s == ls)
            {
                lb = mid;
                ls = s;
            }
            else
            {
                ub = mid;
            }
        }
        else
        {
            if(s == ls)
            {
                ub = mid;
            }
            else
            {
                lb = mid;
                ls = s;
            }
        }
        //cout << lb << " " << ub << "\n";
        cnt++;
    }
    
    
    return 0;
}