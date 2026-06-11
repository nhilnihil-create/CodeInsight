#include<bits/stdc++.h>
using namespace std;

string S;
int cnt[3] = {0};

int main()
{
    cin >> S;
    for(int i = 0; i < S.size(); i++)cnt[S[i] - 'a']++;
    sort(cnt,cnt + 3);
    if(cnt[2] - cnt[0] <= 1)printf("YES\n");
    else printf("NO\n");
    return 0;
}
