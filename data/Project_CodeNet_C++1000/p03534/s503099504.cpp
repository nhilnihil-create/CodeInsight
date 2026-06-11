#include<iostream>
#include<vector>
#include<queue>
#include<deque>
#include<stack>
#include<cstdio>
#include<utility>
#include<algorithm>
using std::cout;
using std::cin;
using std::endl;


std::string str;
int a=0,b=0,c=0;
int length;

bool istrue(int target){
    if(length/3==target||length/3+1==target){
        return true;
    }
    else return false;
}

int main(void){
	
    cin>>str;
    length=(int)str.length();
    for(int i=0;i<length;i++){
        if(str[i]=='a')a++;
        else if(str[i]=='b')b++;
        else c++;
    }
    if(istrue(a)&&istrue(b)&&istrue(c)){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }

    return 0;
}
