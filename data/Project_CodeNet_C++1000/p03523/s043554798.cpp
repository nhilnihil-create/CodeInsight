#include<bits/stdc++.h>
using namespace std;
string all[]={"KIHBR","KIHBRA","KIHBAR","KIHBARA","KIHABR","KIHABRA","KIHABAR","KIHABARA","AKIHBR","AKIHBRA","AKIHBAR","AKIHBARA","AKIHABR","AKIHABRA","AKIHABAR","AKIHABARA"};
int main()
{
    string s;
    cin>>s;
    bool ans=false;
    for(int i=0;i<16;i++)
    {
        if(s==all[i])
            ans=true;
    }
    if(ans)
    {
        cout<<"YES"<<endl;
    }
    else
        cout<<"NO"<<endl;
    return 0;
}
