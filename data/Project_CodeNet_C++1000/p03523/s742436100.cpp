#include <bits/stdc++.h>
using namespace std;


int main() {
string s;
cin>>s;
int n=s.size();


bool flg= false;

if(s=="KIHBR") flg=true;

if(s=="KIHBRA") flg=true;
if(s=="KIHBAR") flg=true;
if(s=="KIHABR") flg=true;
if(s=="AKIHBR") flg=true;

if(s=="KIHBARA") flg=true;
if(s=="KIHABRA") flg=true;
if(s=="AKIHBRA") flg=true;
if(s=="KIHABAR") flg=true;
if(s=="AKIHBAR") flg=true;
if(s=="AKIHABR") flg=true;

if(s=="KIHABARA") flg=true;
if(s=="AKIHBARA") flg=true;
if(s=="AKIHABRA") flg=true;
if(s=="AKIHABAR") flg=true;

if(s=="AKIHABARA") flg=true;

if(flg) cout<<"YES"<<endl;
else cout<<"NO"<<endl;
}
