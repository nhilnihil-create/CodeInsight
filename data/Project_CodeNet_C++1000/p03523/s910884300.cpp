#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
   	ios::sync_with_stdio(false);
    string s,ans="NO";
    cin>>s;
    char sp[s.size()];
    for (int i = 0; i < s.size(); i++)sp[i]=s[i];
    if(s.size()>9)ans="NO";
    else if(strstr(sp,"KIHABAR")!=NULL||(strstr(sp,"KIHBAR")!=NULL&&s.size()<=8)||(strstr(sp,"KIHABR")!=NULL&&s.size()<=8)||(strstr(sp,"KIHBR")!=NULL&&s.size()<=7)){
        if(((sp[0]=='A'&&sp[1]=='K')||(sp[0]=='K'&&sp[1]=='I'))&&((sp[s.size()-1]=='R'&&(sp[s.size()-2]=='A'||sp[s.size()-2]=='B'))||(sp[s.size()-1]=='A'&&sp[s.size()-2]=='R')))ans="YES";
    }
    cout<<ans<<'\n';
}