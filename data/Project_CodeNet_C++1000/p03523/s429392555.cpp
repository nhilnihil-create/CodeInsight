#include <iostream>
#include <string>
using namespace std;


//AKIBAHARA

int main(){
	string S;
	cin>>S;
	
	size_t KIH_pos = S.npos;
	size_t B_pos;
	size_t B_pos1 = S.npos;
	size_t B_pos2 = S.npos;
	
	if(S.size()>9){
		cout<<"NO";
	}
	else if((KIH_pos=S.find("KIH"))==S.npos||KIH_pos>1||(KIH_pos==1&&S[0]!='A')){
		cout<<"NO";
	}else if((((B_pos1=S.find("BAR",KIH_pos+3))==S.npos)&&((B_pos2=S.find("BR",KIH_pos+3))==S.npos))||(((B_pos=B_pos1==S.npos?B_pos2:B_pos1)-KIH_pos-2)>2)||(S[B_pos-1]!='A'&&S[B_pos-1]!='H')){
//		cerr<<"B_POS - K POS "<<B_pos<<" "<<KIH_pos<<" "<<B_pos-KIH_pos-2<<"\n";
//		if((S[B_pos-1]!='A'&&S[B_pos-1]!='H')) cerr<<" FAIL LAST\n";
		cout<<"NO";
	}else{
		cerr<<"B_POS - K POS "<<B_pos<<" "<<KIH_pos<<"\n";
		cout<<"YES";
	}
	cout<<"\n";
	return 0;
}