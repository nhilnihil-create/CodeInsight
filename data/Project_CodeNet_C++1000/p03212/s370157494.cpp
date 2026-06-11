#include <bits/stdc++.h>
using namespace std;

int n, flag=0, ans=0;
vector<int> bi;

//0~pa-1を長さnで生成、合計pa^n個生成
void bitgen(int len){
  	if(flag) return;

	//生成完了時の処理
	if(len==0){
      	int d=0;
      	vector<int> cnt(10, 0);
      
		/*for(int i=0;i<bi.size();i++){
          cout<< bi[bi.size()-1-i];
        }
      	cout<< endl;*/

		for(int i=0;i<bi.size();i++){
          	d+=bi[bi.size()-1-i]*pow(10, bi.size()-1-i);
          	cnt[bi[bi.size()-1-i]]=1;
          	if(bi[bi.size()-1-i]==0 && cnt[3]+cnt[5]+cnt[7]>0) return;
		}
      	//cout<< "d=" << d <<endl;
      
      	if(n<d){
          	flag=1;
          	return;
        }
      
      	if(cnt[3]*cnt[5]*cnt[7]==1) ans++;
      	//cout<< "#" <<endl;
		return;
	}

  	bi[len-1]=0;
	bitgen(len-1);
  	bi[len-1]=3;
	bitgen(len-1);
  	bi[len-1]=5;
	bitgen(len-1);
  	bi[len-1]=7;
	bitgen(len-1);
}

int main(){

  	string s;
	cin>> n;
  
  	s=to_string(n);

	bi.resize(s.size());
	bitgen(s.size());

	cout<< ans <<endl;

	return 0;
}