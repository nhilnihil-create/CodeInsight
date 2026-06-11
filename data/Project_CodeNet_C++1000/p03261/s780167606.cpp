#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    set<string>s;
    string prev_word,word;
    cin>>word;
    s.insert(word);
    --n;
    bool ans = true;
    while(n--)
    {
        prev_word = word;
        cin>>word;
        if(s.count(word)!=0)
            ans = false;
        if(prev_word[prev_word.size()-1]!=word[0])
            ans = false;
        s.insert(word);
    }
    if(ans)
    cout<<"Yes";
    else
    cout<<"No";
    return 0;
}
