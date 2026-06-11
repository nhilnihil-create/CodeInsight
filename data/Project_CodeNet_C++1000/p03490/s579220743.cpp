#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
	string s;
	cin >> s;
	int x,y;
	cin >> x >> y;

	int sx = 0;
	int sid = 0;
	for(int i = 0;i < s.size();i++){
		if(s[i] == 'T')break;
		sx++;
		sid = i;
	}

	vector<int> lr;
	vector<int> ud;
	int sum_lr = sx;
	int sum_ud = 0;
	bool now_x = true;
	for(int i = sx != 0 ? sid + 1 : 0;i < s.size();i++){
		int count_T = 0;
		int j = i;
		while(j < s.size() && s[j] == 'T'){
			j++;
			count_T++;
		}

		int count_F = 0;
		int k = j;
		while(k < s.size() && s[k] == 'F'){
			count_F++;
			k++;
		}

		//
		if(count_T % 2 == 1)now_x = !now_x;

		if(now_x){
			lr.push_back(count_F);
			sum_lr += count_F;
		}
		else{
			ud.push_back(count_F);
			sum_ud += count_F;
		} 
		i = k - 1;
	}


	vector<vector<bool>> dp_lr(lr.size()+1,vector<bool>(sum_lr * 2 + 1,false));
	dp_lr[0][sum_lr + sx] = true;
	for(int i = 0;i < lr.size();i++){
		for(int j = 0;j <= sum_lr * 2;j++){
			if(dp_lr[i][j]){
				dp_lr[i+1][j+lr[i]] = true;
				dp_lr[i+1][j-lr[i]] = true;
			}
		}
	}
	vector<vector<bool>> dp_ud(ud.size()+1,vector<bool>(sum_ud * 2 + 1,false));
	dp_ud[0][sum_ud] = true;
	for(int i = 0;i < ud.size();i++){
		for(int j = 0;j <= sum_ud * 2;j++){
			if(dp_ud[i][j]){
				dp_ud[i+1][j+ud[i]] = true;
				dp_ud[i+1][j-ud[i]] = true;
			}
		}
	}


	if(sum_lr + x > sum_lr * 2 || sum_ud + y > sum_ud * 2 || sum_lr + x < 0 || sum_ud + y < 0){
		cout << "No" << endl;
		return 0;
	}

	if(dp_lr[lr.size()][sum_lr+x] && dp_ud[ud.size()][sum_ud+y])cout << "Yes" << endl;
	else cout << "No" << endl;
}
