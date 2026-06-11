#include<iostream>
#include<string>

int main(){
	std::string s;
	std::cin>>s;

	int len= s.size();
	int mid= len/2;
	int left, right;
	char lPrev, rPrev;

	if(len%2==0)
		left= mid-1, right= mid;
	else
		left= mid, right= mid;

	lPrev= s[left], rPrev= s[right];

	for(; left>=0 && right<=len-1; left--, right++){
		if(s[left]!=s[right] || s[left]!= lPrev || s[right]!= rPrev)
			break;

		lPrev= s[left], rPrev=s[right];
	}
	
	std::cout<<std::max(right, len-right)<<std::endl;

	return 0;
}