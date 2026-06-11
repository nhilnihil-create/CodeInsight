#include <bits/stdc++.h>
using namespace std;

int main() {


//long long a,b;
//int *num=new int[4];
//char *s=new char[3];
string s;
cin >> s;

string list[17]={"AKIHABARA","AKIHABAR","AKIHABRA","AKIHBARA","KIHABARA","AKIHABR","AKIHBRA","KIHBARA","AKIHBAR","KIHABRA","KIHABAR","AKIHBR","KIHBRA","KIHABR","KIHBAR","KIHBR"};
int flag=0;
for(string a:list){
const char* c=s.c_str();
const char* b=a.c_str();

if(strcmp(c,b)==0){flag=1;
//cout << a << endl;

}
}
if(flag)
cout << "YES" << endl;
else
cout << "NO" << endl;


}
