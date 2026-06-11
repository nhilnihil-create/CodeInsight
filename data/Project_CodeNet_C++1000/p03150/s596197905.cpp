#include <bits/stdc++.h>
using namespace std;

int main(void)
{

    string s;
    cin >> s;

    int n = s.size();

    string word = "keyence";

    bool check = false;
    for (int i = 0; i < word.size(); i++)
    {
        string a = word.substr(0, i + 1);
        string b = word.substr(i + 1);


        auto x = s.find(a);
        auto y = s.find(b);

        if(x == 0 && s.substr(n-b.size(),n)==b){
            check = true;
            break;
        }

        if (x < n && y < n && x < y){
            if(x > 0 && x+word.size() == n){
                check = true;
                break;
           }
            if (x == 0 && y+b.size() == word.size()){
                check = true;
                break;
            }
            if (x == 0 && y + b.size() == n){
                check = true;
                break;
            }
        }
    }

    if (check)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}