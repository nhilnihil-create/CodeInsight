#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;
string s;
vector <pair<string,string> > v[40][40];
map <string,int> m;
long long int cnt=0;
void rek(int index,int n,string str1,string str2,int b1,int b2) {
	if(index==n) {
		string str="";
		for(int i=str2.size()-1;i>=0;i--) str+=str2[i];
		string s1="";
		s1+=str1;
		s1+=' ';
		s1+=str;
		m[s1]+=1;
		v[b1][b2].push_back(make_pair(str1,str));
		return;
	}
	rek(index+1,n,str1+s[index],str2,b1+1,b2);
	rek(index+1,n,str1,str2+s[index],b1,b2+1);
}
void rek2(int index,int n,string str1,string str2,int b1,int b2) {
	if(index==n) {
		string str="";
		//cout <<"a"<<endl;
		for(int i=str2.size()-1;i>=0;i--) str+=str2[i];
		string s1="";
		s1+=str;
		s1+=' ';
		s1+=str1;
		cnt+=m[s1];
		//cout <<str1<<" "<<str2<<" "<<str<<endl;
		/*for(int i=0;i<v[b2][b1].size();i++) {
			//cout <<v[b2][b1][i].first<<" "<<v[b2][b1][i].second<<endl;
			if(str1+v[b2][b1][i].first==v[b2][b1][i].second+str) cnt+=1;
		}*/
		//cout <<endl;
		return;
	}
	rek2(index+1,n,str1+s[index],str2,b1+1,b2);
	rek2(index+1,n,str1,str2+s[index],b1,b2+1);
}
int main()
{
	int n;
	cin >> n >> s;
	rek(0,n,"","",0,0);
	rek2(n,n*2,"","",0,0);
	cout <<cnt;
	return 0;
}