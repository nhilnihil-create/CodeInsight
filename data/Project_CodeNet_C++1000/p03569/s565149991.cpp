#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define ALL(A) A.begin(),A.end()

// xxabxbxax => 
// abxbxxax => () a () 

vector<int> rev(string s)
{
    vector<int> ans;
    int counter = 0;
    
    if(s[0]!='x') ans.push_back(0);
    else counter++;

    
    for(int i=0;i<s.size()-1;i++)
    {
        if(s[i+1]!='x')
        {
            ans.push_back(counter);
            counter = 0;
        }
        else
        {
            counter++;
            if(i==s.size()-2)
            {
                ans.push_back(counter);
            }
        }
    }
    
    if(s[s.size()-1]!='x') ans.push_back(0);
    return ans;
}

int compare(vector<int> V)
{
    vector<int> V2 = V;
    reverse(ALL(V2));

    vector<int> Max(V.size(),0);
    for(int i=0;i<V.size();i++)
    {
        Max[i] = max(V[i],V2[i]);
    }

    return accumulate(ALL(Max),0) - accumulate(ALL(V),0);
}

bool kai(string s)
{
    string t1;
    for(auto x : s)
    {
        if(x != 'x') t1.push_back(x);
    }

    string t2 = t1;
    reverse(ALL(t2));

    if(t1==t2) return true;
    else return false;
}

int main()
{
    string s;
    cin >> s;

    if(!kai(s))
    {
        cout << "-1" << endl;
        return 0;
    } 

    vector<int> V1 = rev(s);

    int ans = compare(V1);

    cout << ans << endl;

    return 0;

}