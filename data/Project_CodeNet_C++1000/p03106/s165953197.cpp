#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int a, b, k;
    cin >> a >> b >> k;
    vector<int> v;
    for (int i = 1; i <= a; i++)
    {
        if(a%i==0)
        {
            if(b%i==0)
            {
                v.push_back(i);
            }
        }
    }
    sort(v.rbegin(), v.rend());
    cout << v[k - 1] << endl;
    return 0;
}