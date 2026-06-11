#include <bits/stdc++.h>
#include <string>
using namespace std;

int e;
char a,b,c,d;

int main(){
    e=0;
	cin>>a>>b>>c>>d;
	if(a==43){
	    e++;
	}
	else if(a==45){
	    e--;
	}
	if(b==43){
	    e++;
	}
	else if(b==45){
	    e--;
	}
	if(c==43){
	    e++;
	}
	else if(c==45){
	    e--;
	}
	if(d==43){
	    e++;
	}
	else if(d==45){
	    e--;
	}
	cout<<e<<endl;
}
