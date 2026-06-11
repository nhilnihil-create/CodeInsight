#include<iostream>
#include<string>
#include<vector>    

using namespace std;

int main(){
    string s;
    int n, q;
    cin >> n >> q;
    cin >> s;
    vector<int> v(n+1);
    v[0]=v[1]=0;
    int cnt = 0;
    for (int i = 1; i < n; i++)
    {
        if(s[i-1]=='A'&&s[i]=='C')
        {
            cnt++;
        }
        v[i + 1] = cnt;

    }
    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        cout << v[r] - v[l] << endl;
    }

    return 0;
}