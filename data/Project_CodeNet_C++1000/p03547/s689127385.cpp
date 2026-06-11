#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int trans(char c){
    if('0'<=c && '9'>=c) return (c-0x30);
	if('A'<=c && 'F'>=c) return (c+0x0A-0x41);
	if('a'<=c && 'f'>=c) return (c+0x0A-0x61);
	return 0;
}

int main(){
    char a,b;
    cin>>a>>b;
    if(trans(a)<trans(b)){
        cout<<"<"<<endl;
    }
    else if(trans(a)>trans(b)){
        cout<<">"<<endl;
    }else{
        cout<<"="<<endl;
    }
    return 0;
}
