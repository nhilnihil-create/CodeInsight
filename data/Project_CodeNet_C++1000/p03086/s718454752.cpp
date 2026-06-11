#include <iostream>
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++) //n回繰り返すときだけ使う普通はforで楽しないのがいいかな

using namespace std;
typedef long long int ll;
int main()
{
    string s;
    cin >> s;

    int count=0;
    int total=0;
    rep(i,s.size())
    {
        if(s[i]=='A'||s[i]=='C'||s[i]=='G'||s[i]=='T')
        {
            count++;
            if(i==(s.size()-1))
                total=max(count,total);
        }
        else
        {
            total = max(total, count);
            count = 0;
        }
    }
        cout <<total <<endl;
        return 0;
        

}
