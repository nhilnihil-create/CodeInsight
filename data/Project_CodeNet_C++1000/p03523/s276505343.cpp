#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793
 
   
int main(){
    string s;
    cin >> s;
    bool a=false;
    if(s=="AKIHABARA")a=true;
    else if(s=="KIHABARA")a=true;
    else if(s=="KIHBARA")a=true;
    else if(s=="KIHABRA")a=true;
    else if(s=="KIHABAR")a=true;
    else if(s=="KIHBRA")a=true;
    else if(s=="KIHBAR")a=true;
    else if(s=="KIHABR")a=true;
    else if(s=="KIHBR")a=true;
    else if(s=="AKIHBARA")a=true;
    else if(s=="AKIHBRA")a=true;
    else if(s=="AKIHBAR")a=true;
    else if(s=="AKIHBR")a=true;
    else if(s=="AKIHABRA")a=true;
    else if(s=="AKIHABAR")a=true;
    else if(s=="AKIHABAR")a=true;
    if(a)cout << "YES" << endl;
    else cout << "NO" << endl;


    
} 
    