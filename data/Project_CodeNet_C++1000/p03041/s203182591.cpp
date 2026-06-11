#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    string s;
    scanf("%d %d",&n, &k);
    cin>>s;
    int len = s.size();

    s[k - 1] = s[k - 1] + 32;


    cout<<s<<endl;
    return 0;
}
/*

int main()
{
    int n, k;
    string s;
    scanf("%d %d", &n, &k);
    cin>>s;
    s[k - 1] = tolower(s[k - 1]);
    cout<<s;
    return 0;
}
*/

