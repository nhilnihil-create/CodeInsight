#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//State
//dp[i][j]: The length of longest common subsequence of s[0...i]
//	and t[0...j]

//Initialization
//if s.at(0)=t.at(0) then dp[0][0] = 1 else dp[0][0] = 0

//Transitions (Only one of s[i] and t[i] can be in LCS[i,j] if they are not equal)
//if s[i]=t[i] then dp[i][j] = dp[i-1][j-1]+1
//else dp[i][j] = max(dp[i-1][j], dp[i][j-1])

//Order of evaluation
//Rowwise or columnwise

//Answer
//dp[len(s)-1][len(t)-1]

//Time Complexity = O(len(s)*len(t))

pair<int,pair<int,int>> dp[3005][3005] = {make_pair(0,make_pair(0,0))};

int main(){
	string s;
	string t;
	cin >> s >> t;
	int m = s.length();
	int n = t.length();
	/*if(s.at(0)==t.at(0)) dp[0][0] = 1;
	else dp[0][0] = 0;*/

	for(int i=0; i<m; i++){
		//start_pos, len_of_substring
		int found = s.substr(0,i+1).find(t.at(0));
		if(found != string::npos){
			dp[i][0] = make_pair(1,make_pair(-1,-1));
		}
		else{
			dp[i][0] = make_pair(0,make_pair(-1,-1));
		}
	}

	for(int i=1; i<n; i++){
		if(t.at(i) == s.at(0)){
			dp[0][i] = make_pair(1,make_pair(-1,-1));
		}
		else{
			dp[0][i] = dp[0][i-1];
		}
	}

	for(int i=1; i<m; i++){
		for(int j=1; j<n; j++){
			if(s.at(i)==t.at(j)){
				dp[i][j] = make_pair(1+dp[i-1][j-1].first, make_pair(i-1,j-1));
			}
			else{
			    pair<int,pair<int,int>> top = dp[i-1][j];
			    pair<int,pair<int,int>> left = dp[i][j-1];
			    if(top.first >= left.first){
			        dp[i][j] = make_pair(top.first, make_pair(i-1,j));
			    }
			    else{
			        dp[i][j] = make_pair(left.first, make_pair(i,j-1));
			    }
			}
		}
	}
	
	string result;
	int i,j;
    pair<int,int> curr = make_pair(m-1,n-1);
    while(true){
        i = curr.first;
        j = curr.second;
        pair<int,int> prev = dp[i][j].second; //cell from which we came to i,j
        if(prev.first<0){
            if(curr.first == 0){
                int index = t.substr(0, curr.second+1).find(s.at(0));
                if(index != string::npos) result = result + s.at(0);
                break;
            }
            else{
                int index = s.substr(0, curr.first+1).find(t.at(0));
                if(index != string::npos) result = result + t.at(0);
                break;       
            }
        }
        if(prev.first == i-1 && prev.second == j-1){
            result = result + s.at(i);
        }
        curr = prev;
    }
    reverse(result.begin(), result.end());
    cout << result << endl;
}

