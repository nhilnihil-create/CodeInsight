#include <bits/stdc++.h>
using namespace std;
map<string,int> mp;
string temp;
int main()
{
    mp["AKIHABARA"]=1;
    mp["KIHABARA"]=1;
    mp["AKIHBARA"]=1;
    mp["AKIHABRA"]=1;
    mp["AKIHABAR"]=1;
    mp["KIHBARA"]=1;
    mp["KIHABRA"]=1;
    mp["KIHABAR"]=1;
    mp["AKIHBRA"]=1;
    mp["AKIHBAR"]=1;
    mp["AKIHABR"]=1;
    mp["KIHBRA"]=1;
    mp["KIHBAR"]=1;
    mp["AKIHBR"]=1;
    mp["KIHABR"]=1;
    mp["KIHBR"]=1;
    cin>>temp;
    if(mp[temp]==1)
        cout<<"YES\n";
    else
        cout<<"NO\n";
}
